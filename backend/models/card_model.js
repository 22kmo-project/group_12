const db = require('../database');  //käytetään database.js edellisestä hakemistosta
const bcrypt = require('bcryptjs');

const saltRounds = 10;

const card = {
  getById: function (id, callback) {
    return db.query('select * from card where card_number=?', [id], callback);
  },
  getAll: function (callback) {
    return db.query('select * from card', callback);
  },
  add: function (add_data, callback) {
    bcrypt.hash(add_data.pincode, saltRounds, function (err, hashedPassword) { //kryptattu pincode tietokantaan
      return db.query(
        'insert into card (card_owner,expiry_date,pincode,debit,credit,locked_pin) values(?,?,?,?,?,?)',
        [add_data.card_owner, add_data.expiry_date, hashedPassword, Boolean(add_data.debit == 1), Boolean(add_data.credit == 1),
        Boolean(add_data.locked_pin == 1)],
        callback);
    });
  },
  delete: function (id, callback) {
    return db.query('delete from card where card_number=?', [id], callback);
  },
  update: function (id, update_data, callback) {
    bcrypt.hash(update_data.pincode, saltRounds, function (err, hashedPassword) { //samoin kortin tietoja päivitettäessä salasana kryptataan
      return db.query(
        'update card set card_owner=?,expiry_date=?, pincode=?, debit=?, credit=?, locked_pin=? where card_number=?',
        [update_data.card_owner, update_data.expiry_date, hashedPassword, Boolean(update_data.debit == 1), Boolean(update_data.credit == 1),
        Boolean(update_data.locked_pin == 1), id],
        callback);
    });
  }
};
module.exports = card;