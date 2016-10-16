<h2>Stocks Wallet</h1>

<table class = "table table-striped">
    
    <thead>
        <tr>
            <th class="text-center">Symbol</th>
            <th class="text-left">Name</th>
            <th class="text-center">Shares</th>
            <th class="text-center">Price</th>
            <th class="text-center">TOTAL</th>
        </tr>
    </thead>
    
    
    <tbody>
        <?php foreach ($positions as $position): ?>
        
        <tr>
            <td class="text-center"><?= strtoupper($position["symbol"]) ?></td>
            <td class="text-left"><?= $position["name"] ?></td>
            <td class="text-center"><?= $position["shares"] ?></td>
            <td class="text-center">$<?= number_format($position["price"], 2) ?></td>
            <td class="text-center">$<?= number_format($position["shares"] * $position["price"], 2) ?></td>
        </tr>
        
        <?php endforeach ?>
    </tbody>
    
</table>

<table class = "table table-striped">
    
    <thead>
        <tr>
            <th class="text-center">Cash</th>
            <th class="text-center">Stock Worth</th>
            <th class="text-center">TOTAL</th>
        </tr>
    </thead>
    
    
    <tbody>
        <tr>
            <td class="text-center">$<?= number_format($cash) ?></td>
            <td class="text-center">$<?= number_format($shares_worth) ?></td>
            <td class="text-center">$<?= number_format($cash + $shares_worth) ?></td>
        </tr>
    </tbody>
    
</table>