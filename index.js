const Express = require('express');
const Tomita = require('./wrapper/index.js');
const path = require('path');

const app = new Express();

console.log(path.resolve(__dirname, 'tomita', 'config.proto'));

app.get('/', (req, response) => {
    new Tomita(
        'Добрый день! Не могу оформить договоры КАСКО, поле улица заблокировано, ошибка при оформлении.',
        path.resolve(__dirname, 'tomita', 'config.proto'),
        function (err, res) {
            console.log(err);
            console.log(res);
            response.send(res);
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