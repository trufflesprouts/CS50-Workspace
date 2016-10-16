<?php

    // configuration
    require("../includes/config.php");
        
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        $rows = CS50::query("SELECT symbol, shares FROM portfolio WHERE user_id = ?", $_SESSION["id"]);
        
        $cashier = CS50::query("SELECT cash FROM users where id = ?", $_SESSION["id"]);
        $cash = $cashier[0]["cash"];
        
        $positions = [];
        foreach ($rows as $row)
        {
            $stock = lookup($row["symbol"]);
            if ($stock !== false)
            {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
            ];
            }
            else
            {
            apologize("A Terrible Thing Happened");
            }
        }
        
        // render portfolio
        render("sell_form.php", ["cash" => $cash, "positions" => $positions, "title" => "Sell"]);
    }
    
    
     // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $shares_rows = CS50::query("SELECT shares FROM portfolio WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["company"]);
        $shares = $shares_rows[0]["shares"];
        
        if ($_POST["shares"] > $shares)
        {
            apologize("You don't have that many shares");
        }
        else
        {
            $company = lookup($_POST["company"]);
            CS50::query("UPDATE portfolio SET shares = shares - ? WHERE user_id = ? AND symbol = ?", $_POST["shares"], $_SESSION["id"], $_POST["company"]);
            CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?",$_POST["shares"] * $company["price"], $_SESSION["id"]);
            CS50::query("INSERT IGNORE INTO history (user_id, transaction, symbol, shares, price) VALUES(?, 'sell', ?, ?, ?)", $_SESSION["id"], $_POST["company"], $_POST["shares"], $company["price"]);
            render("sell.php", ["shares" => $_POST["shares"], "company" => $company["name"], "price" => ($_POST["shares"] * $company["price"]), "title" => "Sold!"]);
        }
        
    }
    

?>


