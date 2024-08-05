const net = require('net');
const fs = require('fs');
const path = require('path');

const PORT = 5000; // Port to listen on
const OUTPUT_FILE = 'received_file'; // Name of the file to save

const server = net.createServer((socket) => {
    console.log('Client connected');
    const writeStream = fs.createWriteStream(path.join(__dirname, OUTPUT_FILE));

    socket.pipe(writeStream);

    socket.on('end', () => {
        console.log('File received successfully.');
    });

    socket.on('error', (err) => {
        console.error('Error:', err.message);
    });
});

server.listen(PORT, () => {
    console.log(`Server listening on port ${PORT}`);
});
/////////////////////////////////////////////

file-transfer/
├── server.js
├── client.js
└── file_to_send.txt (Only on sender system)


///////////////////////////////////////////

const net = require('net');
const fs = require('fs');
const path = require('path');

const PORT = 5000; // Port of the receiver
const HOST = 'receiver_ip'; // IP address of the receiving system
const FILE_TO_SEND = 'file_to_send.txt'; // File to send

const client = new net.Socket();

client.connect(PORT, HOST, () => {
    console.log('Connected to server');

    const readStream = fs.createReadStream(path.join(__dirname, FILE_TO_SEND));
    readStream.pipe(client);
});

client.on('error', (err) => {
    console.error('Error:', err.message);
});

client.on('close', () => {
    console.log('Connection closed');
});
