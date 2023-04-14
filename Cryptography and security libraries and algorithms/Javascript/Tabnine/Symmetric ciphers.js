const crypto = require('crypto');
const key = crypto.randomBytes(32);
const cipher = crypto.createCipheriv('aes-256- ctr', key, '');