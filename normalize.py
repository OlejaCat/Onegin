banned_letters = ["I", "V", "X"]
banned_symbols = ['"', "«", "»", "\t", " ", "'", "`"]


with open("onegin_files/onegin") as f:
    with open("onegin_files/onegin_normalized.txt", "w") as out:
        for line in f:
            if all(x not in line for x in banned_letters):
                for symbol in banned_symbols:
                    line = line.strip(symbol)
                if line.strip():
                    out.write(line)

