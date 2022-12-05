const express = require('express');  
const router = express.Router();
const bcrypt = require('bcryptjs');
const card = require('../models/card_model');  
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');


router.post('/', 
  function(request, response) {
    if(request.body.card_number && request.body.pincode){   //tietokannasta haetaan tunnukset
      const card_number = request.body.card_number;
      const pincode = request.body.pincode;
        card.checkPassword(card_number, function(dbError, dbResult) {    
          if(dbError){
            response.json(dbError.errno);   
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(pincode,dbResult[0].pincode, function(err,compareResult) { 
                if(compareResult) {                                             
                  console.log("success");
                  const token = generateAccessToken({ username: card_number });
                  response.send(token);   
                }
                else {
                    console.log("wrong password");
                    response.send(false);
                }			
              }
              );
            }
            else{
              console.log("user does not exists");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("username or password missing");
      response.send(false);
    }
  }
);

function generateAccessToken(username) { 
  dotenv.config();
  return jwt.sign(username, process.env.MY_TOKEN, { expiresIn: '1800s' });
}

module.exports=router;