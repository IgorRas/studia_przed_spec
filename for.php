<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Przykład 2</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>

<body>
    <table>
        <?php for($i=0; $i<10; $i++): ?>
        <?php if($i%2 == 0): ?>
            <tr style="background-color: yellow;">
        <?php for($j=0; $j<1; $j++): ?>
            <td> <?php echo "Paragraf #$i"; ?>
            </td>
            <?php endfor ?>
        </tr>
        <?php else:  ?>
            <tr>
        <?php for($j=0; $j<1; $j++): ?>
            <td> <?php echo "Paragraf #$i"; ?>
            </td>
            <?php endfor ?>
        </tr>
        <?php endif ?>
        <?php endfor ?>
 
    </table>
</body>

</html>