#include "UIhtml.h"

String html_home = R"rawliteral(
<!DOCTYPE html>
<html lang="vi">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>Birthday Greeting</title>

    <style>
        * {
            box-sizing: border-box;
        }

        body {
            margin: 0;
            min-height: 100vh;

            display: flex;
            justify-content: center;
            align-items: center;

            font-family: Arial, sans-serif;
            background: #f4f6f8;
        }

        .container {
            width: 90%;
            max-width: 450px;

            background: white;
            padding: 30px;

            border-radius: 16px;

            box-shadow: 0 8px 25px rgba(0, 0, 0, 0.12);
        }

        h1 {
            text-align: center;
            margin-bottom: 10px;
        }

        .description {
            text-align: center;
            color: #666;
            margin-bottom: 25px;
        }

        label {
            display: block;
            margin-top: 15px;
            margin-bottom: 6px;

            font-weight: bold;
        }

        input {
            width: 100%;
            padding: 12px;

            border: 1px solid #ccc;
            border-radius: 8px;

            font-size: 16px;
        }

        input:focus {
            outline: none;
            border-color: #555;
        }

        button {
            width: 100%;

            margin-top: 25px;
            padding: 13px;

            border: none;
            border-radius: 8px;

            background: #222;
            color: white;

            font-size: 16px;
            cursor: pointer;
        }

        button:hover {
            background: #444;
        }
    </style>
</head>

<body>

    <div class="container">

        <h1>Birthday Greeting</h1>

        <p class="description">
            Nhập thông tin để tạo lời chúc sinh nhật
        </p>

        <form action="/work" method="GET">

            <label for="name">
                Tên người được chúc
            </label>

            <input
                type="text"
                id="name"
                name="name"
                placeholder="Nhập tên..."
                required
            >

            <label for="count">
                Thời gian đếm ngược
            </label>

            <input
                type="number"
                id="count"
                name="count"
                min="0"
                max="9"
                value="5"
                required
            >

            <button type="submit">
                Bắt đầu
            </button>

        </form>

    </div>

</body>
</html>
)rawliteral";

String html_success = R"rawliteral(
<!DOCTYPE html>
<html lang="vi">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>Success</title>

    <style>
        * {
            box-sizing: border-box;
        }

        body {
            margin: 0;
            min-height: 100vh;

            display: flex;
            justify-content: center;
            align-items: center;

            font-family: Arial, sans-serif;
            background: #f4f6f8;
        }

        .container {
            width: 90%;
            max-width: 450px;

            background: white;
            padding: 35px;

            text-align: center;

            border-radius: 16px;

            box-shadow: 0 8px 25px rgba(0, 0, 0, 0.12);
        }

        .success-icon {
            font-size: 50px;
            margin-bottom: 10px;
        }

        h1 {
            margin-bottom: 10px;
        }

        p {
            color: #666;
            line-height: 1.5;
        }

        button {
            width: 100%;

            margin-top: 20px;
            padding: 13px;

            border: none;
            border-radius: 8px;

            background: #222;
            color: white;

            font-size: 16px;
            cursor: pointer;
        }

        button:hover {
            background: #444;
        }
    </style>
</head>

<body>

    <div class="container">

        <div class="success-icon">
            ✓
        </div>

        <h1>Đăng ký thành công!</h1>

        <p>
            Hệ thống đã nhận thông tin và bắt đầu thực hiện lời chúc.
        </p>

        <button onclick="window.location.href='/'">
            Quay lại trang chủ
        </button>

    </div>

</body>
</html>
)rawliteral";