"use strict";

Object.defineProperty(exports, "__esModule", { value: true });
var jsonwebtoken_1 = require("jsonwebtoken");
exports.default = (function (request) {
    var header = request.req.headers.authorization;
    if (!header)
        return { isAuth: false };
    var token = header.split(" ");
    if (!token)
        return { isAuth: false };
    var decodeToken;
    try {
        decodeToken = jsonwebtoken_1.default.verify(token[1], "JWT_ACCESS_TOKEN_SECRET");
    }
    catch (err) {
        return { isAuth: false };
    }
    if (!!!decodeToken)
        return { isAuth: false };
    return { isAuth: true, userId: decodeToken.userId };
});
