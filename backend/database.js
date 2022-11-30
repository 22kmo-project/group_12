const mysql = require('mysql');    //Tällä luodaan yhteys tietokantaan
const connection = mysql.createPool({
  host: 'localhost',
  user: 'hannu',
  password: 'netpass',
  database: 'banksimuldb_exp'
});
module.exports = connection;