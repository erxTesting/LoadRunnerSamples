# Loopy4.bat - LoadRunner Utility Script

## **Overview**

This batch file is a utility script designed to manage and execute LoadRunner scripts locally or remotely. It includes features for editing, viewing, and running scripts, as well as managing persistent variables and configurations.

---

## **Version History**

| Version     | Date       | Author | Description                                                                 |
|-------------|------------|--------|-----------------------------------------------------------------------------|
| 0.001-beta  | 2015-07-22 | erx    | Initial version, providing the framework                                   |
| 0.002-beta  | 2015-07-23 | erx    | Added output parsing and persistent variables                              |
| 0.003-beta  | 2015-09-28 | erx    | Added view file list in CMD window                                         |
| 0.004-beta  | 2025-05-05 | erx    | Updated static information, added comments, and improved functionality     |

---

## **Features**

1. **Persistent Variables Management**:
   - Stores variables like `dataGroup`, `loopyEditor`, `loopyList`, `fileOpen`, and `loopySvr` persistently.
   - Saves and restores these variables using helper functions.

2. **Menu System**:
   - Displays a menu and prompts the user for actions.
   - Actions are defined by `:init_` and `:loop_` labels.

3. **Script Execution**:
   - Supports running LoadRunner scripts locally or remotely using `mmdrv.exe` and `PsExec.exe`.

4. **File and Script Management**:
   - Allows editing, viewing, and selecting scripts or files.
   - Parses output files for errors, warnings, and other details.

5. **Helper Functions**:
   - Includes functions for variable persistence, cycling through lists, progress tracking, and delays.

---

## **Code**

### **Persistent Variables**

```bat
set FilePersist=%~dpn0+.cmd
call:setPersist dataGroup=uat
call:setPersist loopyEditor=notepad
call:setPersist loopyList=scripts
call:setPersist fileOpen=output.txt
call:setPersist loopySvr=r2512587a230
