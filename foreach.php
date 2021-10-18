<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Przykład 3</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>

<body>
    <?php
    $kolory = [
        'green','yellow', 'black',
        'blue','red','pink',
        'cyan'
    ];

    echo "<ul>";
        foreach ($kolory as $value) {
        
        echo "<li style='color: $value'>$value </li>";
        
        }
     echo "</ul>";
     ?>
</body>

</html>