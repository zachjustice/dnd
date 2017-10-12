import subprocess
import random

phrases = [
"Darien, help me",
"I'm so alone, Darien",
"Its so cold.",
"Please do something",
"I think I can hear something coming"
]

phrase = random.choice(list(enumerate(phrases)))[1]
subprocess.call(["osascript", "-e", "set volume output volume 5"])
subprocess.call(["say", phrase])
