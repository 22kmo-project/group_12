const express = require('express');
const router = express.Router();
const card = require('../models/card_model');

router.get('/:id?', function(request, response) {
  card.debitOrCreditcheck(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;