const express = require('express');
const router = express.Router();
const transactions = require('../models/transactions_model');

router.get('/:id?', function(request, response) {
    transactions.getTenTransactions(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  });

  module.exports = router;