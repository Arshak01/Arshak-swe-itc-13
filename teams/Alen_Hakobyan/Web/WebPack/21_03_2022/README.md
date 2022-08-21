# 🚀 Welcome to new awesome project!

This project has been created using **webpack-cli**, you can now run

```
npm run build
```

or

```
yarn build
```

to bundle your application

Have done build directory by steps bottom. Used babel-loader to transpile ES2015+ and HtmlWebpackPlugin to generate html file.

  1) npm init -y
  2) npm install --save-dev webpack webpack-cli html-webpack-plugin
  3) changed const config = {
                  entry: "./src/app.js",
                  output: {
                  path: path.resolve(__dirname, "build"),
              },
  4) npm install babel-preset-es2015 --save-dev
  5) npm run build
  6) npm install http-server --save-dev
  7) npm start