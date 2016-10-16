<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <select required class="form-control" name="company">
                <option value="" disabled selected>Select A Company</option>
                <?php foreach ($positions as $position): ?>
                <option value="<?= $position["symbol"] ?>"><?= $position["name"] ?> (<?= $position["shares"] ?> share)</option>
                <?php endforeach ?>
            </select>
        </div>
        <div class="form-group">
            <input required class="form-control" autofocus class="form-control" name="shares" placeholder="Number of Shares" type="number" min="0" step="1"/>
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                Sell
            </button>
        </div>
    </fieldset>
</form>
