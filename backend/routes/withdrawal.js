const express = require('express');
const router = express.Router();
const transactions = require('../models/transactions_model');

router.post('/',
function(request, response) {
    const { account_number, card_number, amount } = request.body
    transactions.withdrawal(account_number, card_number, amount, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json({"status": "200", "result": dbResult});
      }
    });
});

module.exports = router;
