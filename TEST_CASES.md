# Basic Test Cases

| No. | Test | Input / Action | Expected Result |
|---|---|---|---|
| 1 | Register valid holder | H001 + valid details | Success message |
| 2 | Duplicate holder | Register H001 again | Duplicate ID error |
| 3 | Empty holder field | Empty name or ID | Validation error |
| 4 | Invalid phone length | Less/more than 10 chars | Phone validation error |
| 5 | Search holder | Search H001 | Holder details shown |
| 6 | Unknown holder | Search H999 | Not found message |
| 7 | Select valid plan | H001 + Life + positive coverage | Success message |
| 8 | Invalid coverage | Coverage <= 0 | Validation error |
| 9 | Premium before plan | Holder with no plan | Select plan first message |
| 10 | Premium after plan | H001 after plan selection | Premium displayed |
| 11 | Submit claim | C001 + H001 + positive amount | Pending claim created |
| 12 | Duplicate claim ID | C001 again | Duplicate ID error |
| 13 | Search claim | Search C001 | Claim details shown |
| 14 | Update claim | Set C001 to Approved | Status updated |
