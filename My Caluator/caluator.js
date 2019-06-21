function put(char) {
            var display = document.getElementById('view');
            display.value += char;
        }
        function calculate() {
            var display = document.getElementById('view');
            var result = eval(display.value);
            document.getElementById('result').value = result;
        }
        function reset() {
            document.getElementById('view').value = "";
            document.getElementById('result').value = "";
        }