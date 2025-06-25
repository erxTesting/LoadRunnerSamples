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