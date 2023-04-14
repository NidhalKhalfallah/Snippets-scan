const tls = require('tls');
const net = require('net');
//establish a connection to https://www.google.com/
const https = require('https');
const fs = require('fs');
const path = require('path');
const express = require('express');
const bodyParser = require('body-parser');
const app = express();
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.text());
app.use(bodyParser.json({ type: 'application/vnd.api+json' }));
app.use(bodyParser.urlencoded({ extended: true }));

const port = process.env.PORT || 3000;
const server = app.listen(port, () => {
    console.log(`Server listening on port ${port}`);
});
const io = require('socket.io')(server);
const { v4: uuidv4 } = require('uuid');

const users = {};
const rooms = {};
const messages = {};

io.on('connection', (socket) => {

    socket.on('join', (room) => {

        if (!rooms[room]) {
            rooms[room] = [];
        }

        socket.join(room);


            rooms[room].push(socket.id);

            console.log(rooms[room]);

                    socket.emit('message', {
                        type:'success',
                        message: `Welcome to ${room}!`
                    });

                                        socket.broadcast.to(room).emit('message', {
                        type:'success',
                        message: `${socket.id} has joined the room.`
                    });            