const express = require('express');
const router = express.Router();
const bankuser = require('../models/bankuser_model');  //täältä muokattiin vaan sana bankuser

router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    bankuser.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0]);
      }
    });
  } else {
    bankuser.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});


router.post('/', 
function(request, response) {
  bankuser.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});

router.delete('/:id', 
function(request, response) {
  bankuser.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.put('/:id', 
function(request, response) {
  bankuser.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;
