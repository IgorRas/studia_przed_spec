<?php
$liczbaWierszy = $_POST['liczba_wierszy'] ?? 2;
$liczbaKolumn = $_POST['liczba_kolumn'] ?? 2;
$kolorTla = $_POST['kolor_tla'] ?? 'white';
$parzyste = $_POST['parzyste'] ?? 0;
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>WIT</title>
    <style>
        td {
            border: 1px solid black;
        }
    </style>
</head>

<body style="background-color: <?= $kolorTla ?>">
    <?php if ($parzyste == 1) : ?>
    <table>
        <?php for ($i = 0; $i < $liczbaWierszy; $i++) : ?>
            <?php if ($i%2==0) : ?>
                <tr style="background-color: yellow;">
                    <?php for ($j = 0; $j < $liczbaKolumn; $j++) : ?>
                        <td><?= $i ?>.<?= $j ?></td>
                    <?php endfor; ?>
                </tr>
            <?php else: ?>
                <tr>
                <?php for ($j = 0; $j < $liczbaKolumn; $j++) : ?>
                    <td><?= $i ?>.<?= $j ?></td>
                <?php endfor; ?>
            </tr>
            <?php endif; ?>
        <?php endfor; ?>
    </table>
    <?php else : ?>
        <table>
        <?php for ($i = 0; $i < $liczbaWierszy; $i++) : ?>
            <tr>
                <?php for ($j = 0; $j < $liczbaKolumn; $j++) : ?>
                    <td><?= $i ?>.<?= $j ?></td>
                <?php endfor; ?>
            </tr>
        <?php endfor; ?>
    </table>
    <?php endif; ?>
</body>

</html>