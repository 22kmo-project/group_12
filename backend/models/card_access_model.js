const db = require('../database');

const card_access = {
  getById: function(id, callback) {
    return db.query('select * from card_access where idcard_access=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from card_access', callback);
  },
  add: function(add_data, callback) {
    return db.query(
      'insert into card_access (account_number, card_number) values(?,?)',
      [add_data.account_number, add_data.card_number],
      callback);
  },
  delete: function(id, callback) {
    return db.query('delete from card_access where idcard_access=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    return db.query(
      'update card_access set account_number=?, card_number=? where idcard_access=?',
      [update_data.account_number, update_data.card_number, id],
      callback);
  }
};
module.exports = card_access;