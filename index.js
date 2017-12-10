const Express = require('express');
const Tomita = require('./wrapper/index.js');
const path = require('path');
var bodyParser = require('body-parser');
var data2xml = require("data2xml");
var convert2xml = data2xml({'attrProp': '\$', 'null': 'closed', 'undefined': 'closed'});

const app = new Express();

app.use(bodyParser.json()); // support json encoded bodies
app.use(bodyParser.urlencoded({ extended: true })); // support encoded bodies

app.post('/', (req, response) => {
    new Tomita(
        req.body.text,
        path.resolve(__dirname, 'tomita', 'config.proto'),
        function (err, res) {
            console.log(res);
			response.set('Content-Type', 'text/xml');
			response.send(convert2xml("facts", res));
        }
    );
});

app.listen(3000, (error) => {
    if (error) {
        console.log(error);
    } else {
        console.log('Service has been started on port 3000');
    }
});