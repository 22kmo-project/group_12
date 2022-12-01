const db = require('../database');

const transactions = {
  getById: function(id, callback) {
    return db.query('select * from transactions where idtransactions=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from transactions', callback);
  },
  add: function(add_data, callback) {
    return db.query(
      'insert into transactions (description, account_number, card_number, amount, date_time) values(?,?,?,?,?)',
      [add_data.description, add_data.account_number, add_data.card_number,add_data.amount,add_data.date_time],
      callback);
  },
  delete: function(id, callback) {
    return db.query('delete from transactions where idtransactions=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    return db.query(
      'update transactions set description=?,account_number=?, card_number=?, amount=?, date_time=? where idtransactions=?',
      [update_data.description, update_data.account_number, update_data.card_number, update_data.amount, update_data.date_time, id],
      callback);
  }
};
module.exports = transactions;