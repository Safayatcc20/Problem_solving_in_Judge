import requests
from bs4 import BeautifulSoup

# Your usernames on each platform
USERNAMES = {
    "Codeforces": "Rifat02",
    "CSES": "Safayatcc20",
    "LeetCode": "safayatcc99",
    "CodeChef": "safayatcc20",
    "AtCoder": "safayatcc20",
    "SPOJ": "safayatcc99",
    "LightOJ": "safayatcc20",
    "Toph": "safayatcc20",
    "Vjudge": "safayat20",
    "HackerRank": "safayatcc20",
    "UVa": "safayatcc20",
    "HackerEarth": "Safayat",
}

# Manual override for actual counts (if scraping is inaccurate)
OVERRIDE_COUNTS = {
    "Codeforces": 1632,
    "CSES": 40,
    "LeetCode": 57,
    "CodeChef": 233,
    "AtCoder": 200,
    "SPOJ": 19,
    "LightOJ": 13,
    "Toph": 60,
    "Vjudge": 416,
    "HackerRank": 34,
    "UVa": 9,
    "HackerEarth": 3,
}

def fetch_codeforces(username):
    url = f"https://codeforces.com/profile/{username}"
    res = requests.get(url)
    soup = BeautifulSoup(res.text, "html.parser")
    try:
        val = soup.select_one("div.info span.value").text.strip()
        return int(val)
    except:
        return 0

def fetch_cses(username):
    url = f"https://cses.fi/user/{username}"
    res = requests.get(url)
    soup = BeautifulSoup(res.text, "html.parser")
    try:
        solved = soup.select_one("div.stats > div:nth-child(2) > span").text.strip()
        return int(solved)
    except:
        return 0

def fetch_leetcode(username):
    # LeetCode scraping is tricky, recommend API, so return 0 to fallback
    return 0

def fetch_codechef(username):
    url = f"https://www.codechef.com/users/{username}"
    res = requests.get(url)
    soup = BeautifulSoup(res.text, "html.parser")
    try:
        solved = soup.find("section", {"class": "rating-data-section problems-solved"}).find("h5").text
        import re
        count = int(re.findall(r'\d+', solved)[0])
        return count
    except:
        return 0

def fetch_atcoder(username):
    url = f"https://atcoder.jp/users/{username}"
    res = requests.get(url)
    soup = BeautifulSoup(res.text, "html.parser")
    try:
        ac_count = 0
        table = soup.find("table", {"class": "table table-bordered table-striped small"})
        if table:
            rows = table.find_all("tr")
            for row in rows:
                if row.find("td", string="AC"):
                    ac_count += 1
        return ac_count
    except:
        return 0

def fetch_spoj(username):
    url = f"https://www.spoj.com/users/{username}/"
    res = requests.get(url)
    soup = BeautifulSoup(res.text, "html.parser")
    try:
        text = soup.find(text="Problems solved:")
        if text:
            count = int(text.parent.find_next_sibling(text=True).strip())
            return count
        return 0
    except:
        return 0

def fetch_lightoj(username):
    # No scrape access
    return 0

def fetch_toph(username):
    url = f"https://toph.co/u/{username}"
    res = requests.get(url)
    soup = BeautifulSoup(res.text, "html.parser")
    try:
        solved = soup.find("span", {"id": "solved-count"})
        if solved:
            return int(solved.text.strip())
        return 0
    except:
        return 0

def fetch_vjudge(username):
    return 0  # No scraper

def fetch_hackerrank(username):
    url = f"https://www.hackerrank.com/rest/hackers/{username}/profile"
    res = requests.get(url)
    try:
        data = res.json()
        return int(data['model']['solved_challenges'])
    except:
        return 0

def fetch_uva(username):
    return 0  # No scraper

def fetch_hackerearth(username):
    return 0  # No scraper

FETCH_FUNCTIONS = {
    "Codeforces": fetch_codeforces,
    "CSES": fetch_cses,
    "LeetCode": fetch_leetcode,
    "CodeChef": fetch_codechef,
    "AtCoder": fetch_atcoder,
    "SPOJ": fetch_spoj,
    "LightOJ": fetch_lightoj,
    "Toph": fetch_toph,
    "Vjudge": fetch_vjudge,
    "HackerRank": fetch_hackerrank,
    "UVa": fetch_uva,
    "HackerEarth": fetch_hackerearth,
}

def main():
    results = {}
    total = 0
    for platform, username in USERNAMES.items():
        if platform in OVERRIDE_COUNTS:
            count = OVERRIDE_COUNTS[platform]
        else:
            count = FETCH_FUNCTIONS[platform](username)

    


    with open("README.md", "r") as f:
        content = f.read()

    stats_table = "| Platform     | Username     | Solved Problems |\n"
    stats_table += "|--------------|--------------|-----------------|\n"
    for platform in USERNAMES.keys():
        stats_table += f"| {platform:<12} | {USERNAMES[platform]:<12} | {results[platform]:<15} |\n"
    stats_table += f"| **Total**    |              | **{total}**        |\n"

    start_marker = "<!-- stats-start -->"
    end_marker = "<!-- stats-end -->"

    before = content.split(start_marker)[0]
    after = content.split(end_marker)[1]

    new_content = before + start_marker + "\n" + stats_table + "\n" + end_marker + after

    with open("README.md", "w") as f:
        f.write(new_content)

if __name__ == "__main__":
    main()
