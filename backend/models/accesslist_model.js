const db = require('../database');

const accesslist = {
  getById: function(id, callback) {
    return db.query('select * from accesslist where idaccesslist=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from accesslist', callback);
  },
  add: function(add_data, callback) {
    return db.query(
      'insert into accesslist (id_user, account_number) values(?,?)',
      [add_data.id_user, add_data.account_number],
      callback);
  },
  delete: function(id, callback) {
    return db.query('delete from accesslist where idaccesslist=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    return db.query(
      'update accesslist set id_user=?, account_number=? where idaccesslist=?',
      [update_data.id_user, update_data.account_number, id],
      callback);
  }
};
module.exports = accesslist;