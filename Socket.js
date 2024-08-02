const net = require('net');
const fs = require('fs');

// Create a server object
const server = net.createServer((socket) => {
  console.log('Client connected');
  
  // Create a writable stream to save the received file
  const fileStream = fs.createWriteStream('received_file');

  // Pipe the socket data to the file stream
  socket.pipe(fileStream);

  socket.on('end', () => {
    console.log('File received');
  });

  socket.on('error', (err) => {
    console.error('Socket error:', err);
  });
});

// Listen on port 4000
server.listen(4000, () => {
  console.log('Server listening on port 4000');
});

server.on('error', (err) => {
  console.error('Server error:', err);
});


const net = require('net');
const fs = require('fs');

// Create a connection to the server
const client = net.createConnection({ port: 4000, host: 'RECEIVER_MACHINE_IP' }, () => {
  console.log('Connected to server');

  // Create a readable stream to read the file
  const fileStream = fs.createReadStream('file_to_send');

  // Pipe the file stream to the socket
  fileStream.pipe(client);

  fileStream.on('end', () => {
    client.end();
  });

  fileStream.on('error', (err) => {
    console.error('File stream error:', err);
  });
});

client.on('end', () => {
  console.log('File sent');
});

client.on('error', (err) => {
  console.error('Client error:', err);
});

Steps to Run the Code
Set up the server:
Copy the server.js file to the receiver machine.
Open a terminal on the receiver machine.
Navigate to the directory containing server.js.
Run the server: node server.js.
Set up the client:
Copy the client.js file to the sender machine.
Make sure you have a file named file_to_send in the same directory as client.js.
Open a terminal on the sender machine.
Navigate to the directory containing client.js.
Replace 'RECEIVER_MACHINE_IP' in client.js with the actual IP address of the receiver machine.
Run the client: node client.js.



