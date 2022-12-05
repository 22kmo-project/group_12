const db = require('../database');

const bankaccount = {
  getById: function(id, callback) {
    return db.query('select * from bankaccount where account_number=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from bankaccount', callback);
  },
  add: function(add_data, callback) {
    return db.query(
      'insert into bankaccount (account_number, id_user, balance, credit, credit_cap) values(?,?,?,?,?)',
      [add_data.account_number, add_data.id_user, add_data.balance, Boolean(add_data.credit == 1), add_data.credit_cap],
      callback);
  },
  delete: function(id, callback) {
    return db.query('delete from bankaccount where account_number=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    return db.query(
      'update bankaccount set account_number=?, id_user=?, balance=?, credit=?, credit_cap=? where account_number=?',
      [update_data.account_number, update_data.id_user, update_data.balance, Boolean(update_data.credit == 1), update_data.credit_cap, id],
      callback);
  }
};
module.exports = bankaccount;