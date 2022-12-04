const db = require('../database');

const bankuser = {
  getById: function(id, callback) {
    return db.query('select * from bankuser where id_user=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from bankuser', callback);
  },
  add: function(add_data, callback) {
    return db.query(
      'insert into bankuser (fname, lname, streetname, zipcode, city, phonenumber) values(?,?,?,?,?,?)',
      [add_data.fname, add_data.lname, add_data.streetname, add_data.zipcode, add_data.city, add_data.phonenumber],
      callback);
  },
  delete: function(id, callback) {
    return db.query('delete from bankuser where id_user=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    return db.query(
      'update bankuser set fname=?, lname=?, streetname=?, zipcode=?, city=?, phonenumber=? where id_user=?',
      [update_data.fname, update_data.lname, update_data.streetname, update_data.zipcode, update_data.city, update_data.phonenumber, id],
      callback);
  }
};
module.exports = bankuser;