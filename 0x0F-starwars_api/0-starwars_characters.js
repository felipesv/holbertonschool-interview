#!/usr/bin/node
/*
  Star Wars Characters
*/
const request = require('request');
const apiUrl = 'https://swapi-api.hbtn.io/api/films/'.concat(process.argv[2]);
request(apiUrl, function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    JSON.parse(body).characters.forEach(element => {
      request(element, function (err, res, bod) {
        if (err) {
          console.log(error);
        } else {
          console.log(JSON.parse(bod).name);
        }
      });
    });
  }
});
