import subprocess
import random
from pathlib import Path

def main():
    # Some colors
    GREEN = "\033[32m"
    RED   = "\033[31m"
    GRAY  = "\033[90m"
    RESET = "\033[0m"
    BOLD  = "\033[1m"

    script_dir = Path(__file__).parent.resolve()
    push_swap_path = script_dir.parent / "push_swap"
    checker_path   = script_dir.parent / "checker_linux" # <- To change the checker, change it from here

    tests = [1, 2, 3, 5, 10, 100, 500]
    print("Numbers\t\tResult\t\tMoves")
    for i in tests:
        # Generate random numb... yes, I'm a human, in case you were wondering.
        random_numbers = random.sample(range(-1000, 1000), i)

        # We get our arguments ready
        stack = ' '.join(str(s) for s in random_numbers)

        # Some preperations
        push_swap = f'{push_swap_path} {stack}'
        checker =  f'{checker_path} {stack}'

        # We get our output and the operations count
        output = subprocess.run(push_swap + '|' + checker, shell=True, capture_output=True, text=True)
        op_count = int(subprocess.run(push_swap + ' | ' + 'wc -l', shell=True, capture_output=True, text=True).stdout.strip())

        # Hopefully no errors here...
        if (output.stderr):
            print("...\nERROR!!")
            print("Make sure push_swap and checker_linux are in the right paths and have the correct permissions!")
            print("This checker assumes both of them are in the root directory of this repo.")
            exit()

        result = output.stdout.strip()
        if (result == 'OK'):
            print(f"[{i}]\t\t{GREEN}{BOLD}OK{RESET}\t\t{GRAY}{op_count}{RESET}")
        else:
            print(f"[{i}]\t\t{RED}{BOLD}OK{RESET}\t\t{GRAY}{op_count}{RESET}")
main()
