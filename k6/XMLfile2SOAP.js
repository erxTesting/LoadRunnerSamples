// JavaScript send variable values from a separate file imbedded in a SOAP XML body requests to a web server with
// parameters to pass to the script

import http from 'k6/http';
import { check } from 'k6';

export let options = {
  stages: [
    { duration: '30s', target: 100 }, // simulate ramp-up of traffic
    { duration: '1m', target: 100 }, // stay at 100 virtual users for 1 minute
    { duration: '30s', target: 0 }, // ramp-down to 0 virtual users
  ],
  thresholds: {
    http_req_duration: ['p(99)<500'], // 99% of requests should be below 500ms
  },
};

export default function () {
  const requestBody = `
    <soapenv:Envelope xmlns:soapenv="http://schemas.xmlsoap.org/soap/envelope/" xmlns:ser="http://service.example.com">
      <soapenv:Header/>
      <soapenv:Body>
        <ser:ExampleRequest>
          <ser:Param1>${__ENV.PARAM_1}</ser:Param1>
          <ser:Param2>${__ENV.PARAM_2}</ser:Param2>
        </ser:ExampleRequest>
      </soapenv:Body>
    </soapenv:Envelope>
  `;
  
  const res = http.post('https://example.com/soap', requestBody, {
    headers: {
      'Content-Type': 'text/xml;charset=UTF-8',
      'SOAPAction': 'http://service.example.com/ExampleService/ExampleRequest'
    }
  });
  
  check(res, {
    'status is 200': (r) => r.status === 200,
  });
}

// Example 2, external file instad of body in script
/* In this example, the script imports the http module from k6 and the sleep function from the standard library. 
The script then reads the SOAP XML body request from a separate file using the open function.

Inside the default function, the script sets the URL and headers for the SOAP request. 
The placeholders in the SOAP XML body are then replaced with variable values using the replace function. 
Finally, the script sends the SOAP request to the web server using the http.post function, and waits 
for a short period of time before sending the next request using the sleep function.

Note that you'll need to replace path/to/soap-request.xml with the actual file path to your SOAP XML body request file, 
and https://example.com/soap-api with the actual URL for your SOAP API. You'll also need to replace the placeholders 
and values in the replace function with your actual variable names and values. */


import http from 'k6/http';
import { sleep } from 'k6';

// Read the SOAP XML body request from a separate file
let body = open('path/to/soap-request.xml');

export default function () {
  let url = 'https://example.com/soap-api';
  let params = {
    headers: {
      'Content-Type': 'text/xml;charset=UTF-8',
      'SOAPAction': 'http://example.com/soap-api/action',
    },
  };

  // Replace placeholders in the SOAP XML body with variable values
  body = body.replace('{variable1}', 'value1');
  body = body.replace('{variable2}', 'value2');
  body = body.replace('{variable3}', 'value3');

  // Send the SOAP request to the web server
  let res = http.post(url, body, params);

  // Wait for a short period of time before sending the next request
  sleep(1);
}