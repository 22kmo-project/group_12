const mysql = require('mysql');    //Tällä luodaan yhteys tietokantaan
const connection = mysql.createPool({
  host: 'localhost',
  user: 'banksimulatm',
  password: 'ATM12',
  database: 'banksimuldb_exp'
});
module.exports = connection;