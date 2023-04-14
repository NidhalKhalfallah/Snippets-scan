const crypto = require('crypto');
//Store a password in a cookie
const cookieParser = require('cookie-parser');
//Store a password in a session
const session = require('express-session');
//Store a password in a session
const passport = require('passport');
//Store a password in a session
const LocalStrategy = require('passport-local').Strategy;
//Store a password in a session
const bcrypt = require('bcryptjs');
//Store a password in a session
const flash = require('connect-flash')