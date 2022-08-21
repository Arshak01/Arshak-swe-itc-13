FROM node:16

WORKDIR app/

COPY packag.json .

RUN npm install

COPY . .

EXPOSE 3000

CMD [ "node", "index.js" ]


