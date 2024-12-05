# Implement-Wireless-Network-Access-System
Create a C program for a basic Wireless Access System that authenticates users with
predefined username-password pairs. The program will prompt users to input their credentials
and validate them against the hardcoded set. If the credentials are valid, the program grants
access; otherwise, it denies access and allows the user to retry until they enter correct
credentials.

------

Upon successful authentication, the program will log the username along with the current
timestamp into a file named connections.log. This logging ensures traceability and
accountability for each connection. The log file must be updated reliably, and any issues with
file operations, such as inability to open or write to the file, should be handled gracefully,
with appropriate error messages displayed to the user.
