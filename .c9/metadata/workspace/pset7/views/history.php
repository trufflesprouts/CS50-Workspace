{"changed":true,"filter":false,"title":"history.php","tooltip":"/pset7/views/history.php","value":"<table class = \"table table-striped\">\n    \n    <thead>\n        <tr>\n            <th class=\"text-left\">Transaction</th>\n            <th class=\"text-left\">Date/Time\t</th>\n            <th class=\"text-left\">Symbol</th>\n            <th class=\"text-left\">Shares</th>\n            <th class=\"text-left\">Price</th>\n        </tr>\n    </thead>\n    \n    \n    <tbody>\n        <?php foreach ($positions as $position): ?>\n        \n        <tr>\n            <td class=\"text-left\"><?= strtoupper($position[\"transaction\"]) ?></td>\n            <td class=\"text-left\"><?= $position[\"datetime\"] ?></td>\n            <td class=\"text-left\"><?= strtoupper($position[\"symbol\"]) ?></td>\n            <td class=\"text-left\"><?= number_format($position[\"shares\"]) ?></td>\n            <td class=\"text-left\">$<?= number_format($position[\"price\"], 2) ?></td>\n        </tr>2\n<?php endforeach ?>\n    </tbody>\n    \n</table>","undoManager":{"mark":2,"position":50,"stack":[[{"start":{"row":20,"column":73},"end":{"row":20,"column":74},"action":"remove","lines":["2"],"id":66}],[{"start":{"row":20,"column":72},"end":{"row":20,"column":73},"action":"remove","lines":[" "],"id":67}],[{"start":{"row":20,"column":71},"end":{"row":20,"column":72},"action":"remove","lines":[","],"id":68}],[{"start":{"row":23,"column":8},"end":{"row":24,"column":0},"action":"insert","lines":["",""],"id":69},{"start":{"row":24,"column":0},"end":{"row":24,"column":8},"action":"insert","lines":["        "]}],[{"start":{"row":24,"column":8},"end":{"row":24,"column":12},"action":"insert","lines":["    "],"id":70}],[{"start":{"row":24,"column":8},"end":{"row":24,"column":12},"action":"remove","lines":["    "],"id":71}],[{"start":{"row":24,"column":4},"end":{"row":24,"column":8},"action":"remove","lines":["    "],"id":72}],[{"start":{"row":24,"column":0},"end":{"row":24,"column":4},"action":"remove","lines":["    "],"id":73}],[{"start":{"row":24,"column":0},"end":{"row":24,"column":4},"action":"insert","lines":["    "],"id":74}],[{"start":{"row":24,"column":4},"end":{"row":25,"column":0},"action":"insert","lines":["",""],"id":75},{"start":{"row":25,"column":0},"end":{"row":25,"column":4},"action":"insert","lines":["    "]}],[{"start":{"row":25,"column":0},"end":{"row":25,"column":4},"action":"remove","lines":["    "],"id":76}],[{"start":{"row":24,"column":4},"end":{"row":25,"column":0},"action":"remove","lines":["",""],"id":77}],[{"start":{"row":24,"column":4},"end":{"row":25,"column":0},"action":"insert","lines":["",""],"id":78},{"start":{"row":25,"column":0},"end":{"row":25,"column":4},"action":"insert","lines":["    "]}],[{"start":{"row":25,"column":0},"end":{"row":25,"column":4},"action":"remove","lines":["    "],"id":79}],[{"start":{"row":25,"column":0},"end":{"row":25,"column":1},"action":"insert","lines":[" "],"id":80}],[{"start":{"row":25,"column":1},"end":{"row":25,"column":2},"action":"insert","lines":[" "],"id":81}],[{"start":{"row":25,"column":2},"end":{"row":25,"column":3},"action":"insert","lines":[" "],"id":82}],[{"start":{"row":25,"column":3},"end":{"row":25,"column":4},"action":"insert","lines":[" "],"id":83}],[{"start":{"row":25,"column":0},"end":{"row":25,"column":4},"action":"remove","lines":["    "],"id":84}],[{"start":{"row":25,"column":0},"end":{"row":26,"column":0},"action":"remove","lines":["",""],"id":85}],[{"start":{"row":25,"column":0},"end":{"row":25,"column":4},"action":"remove","lines":["    "],"id":86}],[{"start":{"row":25,"column":0},"end":{"row":25,"column":4},"action":"remove","lines":["    "],"id":87}],[{"start":{"row":24,"column":0},"end":{"row":24,"column":1},"action":"insert","lines":[" "],"id":88}],[{"start":{"row":24,"column":1},"end":{"row":24,"column":2},"action":"insert","lines":[" "],"id":89}],[{"start":{"row":24,"column":2},"end":{"row":24,"column":3},"action":"insert","lines":[" "],"id":90}],[{"start":{"row":24,"column":3},"end":{"row":24,"column":4},"action":"insert","lines":[" "],"id":91}],[{"start":{"row":23,"column":0},"end":{"row":23,"column":8},"action":"remove","lines":["        "],"id":92}],[{"start":{"row":22,"column":13},"end":{"row":23,"column":0},"action":"remove","lines":["",""],"id":93}],[{"start":{"row":23,"column":4},"end":{"row":23,"column":8},"action":"remove","lines":["    "],"id":94}],[{"start":{"row":23,"column":0},"end":{"row":23,"column":4},"action":"remove","lines":["    "],"id":95}],[{"start":{"row":22,"column":13},"end":{"row":23,"column":0},"action":"remove","lines":["",""],"id":96}],[{"start":{"row":22,"column":13},"end":{"row":23,"column":0},"action":"insert","lines":["",""],"id":97},{"start":{"row":23,"column":0},"end":{"row":23,"column":8},"action":"insert","lines":["        "]}],[{"start":{"row":23,"column":8},"end":{"row":23,"column":12},"action":"insert","lines":["    "],"id":98}],[{"start":{"row":23,"column":8},"end":{"row":23,"column":12},"action":"remove","lines":["    "],"id":99}],[{"start":{"row":23,"column":8},"end":{"row":23,"column":12},"action":"insert","lines":["    "],"id":100}],[{"start":{"row":23,"column":8},"end":{"row":23,"column":12},"action":"remove","lines":["    "],"id":101}],[{"start":{"row":23,"column":8},"end":{"row":24,"column":0},"action":"insert","lines":["",""],"id":102},{"start":{"row":24,"column":0},"end":{"row":24,"column":8},"action":"insert","lines":["        "]}],[{"start":{"row":24,"column":8},"end":{"row":24,"column":9},"action":"insert","lines":[" "],"id":103}],[{"start":{"row":24,"column":9},"end":{"row":24,"column":10},"action":"insert","lines":[" "],"id":104}],[{"start":{"row":24,"column":10},"end":{"row":24,"column":11},"action":"insert","lines":[" "],"id":105}],[{"start":{"row":24,"column":11},"end":{"row":24,"column":12},"action":"insert","lines":[" "],"id":106}],[{"start":{"row":24,"column":12},"end":{"row":24,"column":13},"action":"insert","lines":[" "],"id":107}],[{"start":{"row":24,"column":12},"end":{"row":24,"column":13},"action":"remove","lines":[" "],"id":108}],[{"start":{"row":24,"column":8},"end":{"row":24,"column":12},"action":"remove","lines":["    "],"id":109}],[{"start":{"row":24,"column":4},"end":{"row":24,"column":8},"action":"remove","lines":["    "],"id":110}],[{"start":{"row":24,"column":0},"end":{"row":24,"column":4},"action":"remove","lines":["    "],"id":111}],[{"start":{"row":23,"column":8},"end":{"row":24,"column":0},"action":"remove","lines":["",""],"id":112}],[{"start":{"row":23,"column":4},"end":{"row":23,"column":8},"action":"remove","lines":["    "],"id":113}],[{"start":{"row":23,"column":0},"end":{"row":23,"column":4},"action":"remove","lines":["    "],"id":114}],[{"start":{"row":22,"column":13},"end":{"row":23,"column":0},"action":"remove","lines":["",""],"id":115}],[{"start":{"row":22,"column":13},"end":{"row":22,"column":14},"action":"insert","lines":["2"],"id":116}]]},"ace":{"folds":[],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":22,"column":14},"end":{"row":22,"column":14},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":21,"state":"start","mode":"ace/mode/php"}},"timestamp":1461247099000}