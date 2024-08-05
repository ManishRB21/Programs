const net = require('net');
const fs = require('fs');
const path = require('path');

// Configuration
const PORT = 5000; // Port to listen on
const FILE_TO_SEND = 'file_to_send.txt'; // File to send (use an empty string if not sending)
const OUTPUT_FILE = 'received_file'; // Name of the file to save

// Handle receiving files
const startServer = () => {
    const server = net.createServer((socket) => {
        console.log('Receiving file...');
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
        console.log(`Listening for incoming connections on port ${PORT}`);
    });
};

// Handle sending files
const sendFile = (host) => {
    if (!fs.existsSync(FILE_TO_SEND)) {
        console.error('Error: File to send does not exist.');
        return;
    }

    const client = new net.Socket();

    client.connect(PORT, host, () => {
        console.log('Connected to receiver');
        const readStream = fs.createReadStream(path.join(__dirname, FILE_TO_SEND));
        readStream.pipe(client);
    });

    client.on('error', (err) => {
        console.error('Error:', err.message);
    });

    client.on('close', () => {
        console.log('Connection closed');
    });
};

// Start server and client logic
const host = 'receiver_ip'; // Replace with the IP address of the receiver if you want to send a file

// Start server
startServer();

// Optionally start file sending (comment out if not needed)
// sendFile(host);
