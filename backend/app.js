var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const jwt = require('jsonwebtoken');

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');
var loginRouter = require('./routes/login');
var debitOrCreditRouter = require('./routes/debit_or_credit');


var cardRouter = require('./routes/card');
var cardAccessRouter = require('./routes/card_access');
var transactionsRouter = require('./routes/transactions');
var withdrawalRouter = require('./routes/withdrawal');
var accesslistRouter = require('./routes/accesslist');
var bankaccountRouter = require('./routes/bankaccount');
var bankuserRouter = require('./routes/bankuser');

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/login', loginRouter);

//app.use(authenticateToken); //kaikki endpointit tämän alla ovat suojattuja, vaatii webtokenin

app.use('/', indexRouter);
app.use('/users', usersRouter);
app.use('/card', cardRouter);
app.use('/transactions', transactionsRouter);
app.use('/withdrawal', withdrawalRouter);
app.use('/card_access', cardAccessRouter);
app.use('/accesslist', accesslistRouter);
app.use('/debit_or_credit', debitOrCreditRouter);
app.use('/bankuser', bankuserRouter);
app.use('/bankaccount', bankaccountRouter);


function authenticateToken(req, res, next) {   
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]
  
    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)
  
    jwt.verify(token, process.env.MY_TOKEN, (err, user) => {
      console.log(err)
  
      if (err) return res.sendStatus(403)
  
      req.user = user
  
      next()
    })
  }


module.exports = app;
