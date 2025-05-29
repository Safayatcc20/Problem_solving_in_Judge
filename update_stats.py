import requests
from bs4 import BeautifulSoup

def fetch_codeforces_solved(username):
    url = f'https://codeforces.com/profile/{username}'
    res = requests.get(url)
    soup = BeautifulSoup(res.text, 'html.parser')
    solved = 0
    try:
        solved = int(soup.find('div', class_='info').find_all('ul')[0].find_all('li')[0].find('span', class_='value').text.strip())
    except:
        pass
    return solved

def update_readme(codeforces_count):
    with open('README.md', 'r') as f:
        content = f.read()
    new_table = f"""\
| Platform   | Username  | Solved Problems |
|------------|-----------|-----------------|
| Codeforces | Rifat02 | {codeforces_count} |
| **Total**  |           | {codeforces_count} |
"""
    # You can replace the table entirely or just update the count part
    # Here we replace the table between two markers for safety
    start_marker = "<!-- stats-start -->"
    end_marker = "<!-- stats-end -->"
    before = content.split(start_marker)[0]
    after = content.split(end_marker)[1]
    new_content = before + start_marker + '\n' + new_table + '\n' + end_marker + after
    with open('README.md', 'w') as f:
        f.write(new_content)

def main():
    username = 'Rifat02'
    solved_cf = fetch_codeforces_solved(username)
    update_readme(solved_cf)

if __name__ == "__main__":
    main()
