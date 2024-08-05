const net = require('net');
const fs = require('fs');
const path = require('path');

// Configuration
const IS_SENDER = process.env.IS_SENDER === 'true'; // Use environment variable to set the role
const RECEIVER_IP = '10.221.44.42'; // IP of the receiver (PC2)
const FILE_TO_SEND = path.join(__dirname, 'example.txt'); // File to send
const RECEIVED_FILE_PATH = path.join(__dirname, 'received_example.txt'); // File to save received data
const PORT = 4000;

// Function to handle file sending
function sendFile(socket, filePath) {
  const fileStream = fs.createReadStream(filePath);
  fileStream.pipe(socket);

  fileStream.on('end', () => {
    console.log('File sent');
    socket.end();
  });

  fileStream.on('error', (err) => {
    console.error('File stream error:', err);
  });
}

// Function to handle file receiving
function receiveFile(socket, filePath) {
  const fileStream = fs.createWriteStream(filePath);
  socket.pipe(fileStream);

  socket.on('end', () => {
    console.log('File received');
    fileStream.close(() => {
      console.log('File stream closed');
    });
  });

  socket.on('error', (err) => {
    console.error('Socket error:', err);
  });
}

if (IS_SENDER) {
  // Create a client to send data
  const client = net.createConnection({ port: PORT, host: RECEIVER_IP }, () => {
    console.log('Connected to server');
    sendFile(client, FILE_TO_SEND);
  });

  client.on('data', (data) => {
    console.log('Received from server:', data.toString());
  });

  client.on('end', () => {
    console.log('Disconnected from server');
  });

  client.on('error', (err) => {
    console.error('Client error:', err);
  });
} else {
  // Create a server to receive data
  const server = net.createServer((socket) => {
    console.log('Client connected');
    receiveFile(socket, RECEIVED_FILE_PATH);

    socket.on('data', (data) => {
      console.log('Received from client:', data.toString());
    });

    socket.on('end', () => {
      socket.write('File transfer complete', () => {
        console.log('Response sent to client');
      });
    });
  });

  server.listen(PORT, () => {
    console.log(`Server listening on port ${PORT}`);
  });

  server.on('error', (err) => {
    console.error('Server error:', err);
  });
}
