//Write a function to create a session for a user
const crypto = require('crypto');
const sessionSecret = 'my-secret-key';

function createSession(userId) {
  const sessionId = crypto.randomBytes(16).toString('hex');
  const sessionData = {
    userId,
    created: Date.now(),
  };
  const hmac = crypto.createHmac('sha256', sessionSecret);
  hmac.update(sessionId);
  hmac.update(JSON.stringify(sessionData));
  const signature = hmac.digest('hex');
  const sessionCookie = `${sessionId}:${signature}`;
  return sessionCookie;
}