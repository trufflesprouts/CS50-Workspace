<?php

    // configuration
    require("../includes/config.php");
        
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render buy form
        render("buy_form.php", ["title" => "Buy"]);
    }
    
    
     // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $stock = lookup($_POST["symbol"]);
        if ($stock === false)
        {
            apologize("Stock Symbol is Invalid");
        }
        
        $cashier = CS50::query("SELECT cash FROM users where id = ?", $_SESSION["id"]);
        $cash = $cashier[0]["cash"];
        
        $shares_value = $_POST["shares"] * $stock["price"];
        
        if ($shares_value > $cash)
        {
            apologize("You don't have that much money, looser.");
        }
        
        else
        {
            CS50::query("INSERT INTO portfolio (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], strtoupper ($_POST["symbol"]), $_POST["shares"]);
            CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $shares_value, $_SESSION["id"]);
            CS50::query("INSERT IGNORE INTO history (user_id, transaction, symbol, shares, price) VALUES(?, 'buy', ?, ?, ?)", $_SESSION["id"], strtoupper ($_POST["symbol"]), $_POST["shares"], $stock["price"]);
            render("buy.php", ["shares" => $_POST["shares"], "company" =>$stock["name"], "price" => $shares_value, "title" => "Bought!"]);
        }
        
    }
    

?>


