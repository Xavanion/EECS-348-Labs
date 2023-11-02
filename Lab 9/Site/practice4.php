<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Practice 4</title>
</head>
<body>
    <form method="post" action="">
        <label for="number">Enter a number:</label>
        <input type="number" name="number" id="number">
        <input type="submit" name="submit" value="Generate Table">
    </form>
    <?php
    if (isset($_POST['submit'])) {
        //Set variable to post value
        $number = $_POST['number'];
        //Title & border size
        echo "<h2>Multiplication Table from 1 to " . $number . ":</h2>";
        echo "<table border='2'>";
        
        for ($i = 1; $i <= $number; $i++) {
            //Print first cell
            echo "<tr><td>" . $i . "</td>";
            //Loop for same row different cells
            for ($j = 1; $j <= $number; $j++) {
                echo "<td>" . ($i * $j) . "</td>";
            }
            //End Row
            echo "</tr>";
        }
        echo "</table>";
    }
    ?>
</body>
</html>
