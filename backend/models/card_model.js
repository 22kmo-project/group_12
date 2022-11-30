const db = require('../database');  //käytetään database.js edellisestä hakemistosta

const card = {
  getById: function(id, callback) {
    return db.query('select * from card where card_number=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from card', callback);
  },
  add: function(add_data, callback) {
    return db.query(
      'insert into card (card_owner,expired,pincode,debit,credit,locked_pin) values(?,?,?,?,?,?)',
      [add_data.card_owner, add_data.expired, add_data.pincode, add_data.debit, add_data.credit,
         add_data.locked_pin],
      callback);
  },
  delete: function(id, callback) {
    return db.query('delete from card where card_number=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    return db.query(
      'update card set card_owner=?,expired=?, pincode=?, debit=?, credit=?, locked_pin=? where card_number=?',
      [update_data.card_owner, update_data.expired, update_data.pincode, update_data.debit, update_data.credit, 
        update_data.locked_pin, id],
      callback);
  }
};
module.exports = card;