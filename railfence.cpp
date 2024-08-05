(client)
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
(server)
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
//////////////////////////////////////////////

(duplex)
const net = require('net');
const fs = require('fs');
const path = require('path');
const process = require('process');

// Command-line arguments
const mode = process.argv[2]; // 'send' or 'receive'
const PORT = 5000; // Port to listen on/send
const HOST = 'receiver_ip'; // IP address of the receiving system (for sender mode)
const FILE_TO_SEND = 'file_to_send.txt'; // File to send (for sender mode)
const OUTPUT_FILE = 'received_file'; // Name of the file to save (for receiver mode)

if (mode === 'receive') {
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

} else if (mode === 'send') {
    if (!fs.existsSync(FILE_TO_SEND)) {
        console.error('Error: File to send does not exist.');
        process.exit(1);
    }

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

} else {
    console.error('Usage: node file_transfer.js <send|receive>');
}


client.on('close', () => {
    console.log('Connection closed');
});
