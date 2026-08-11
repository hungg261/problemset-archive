import json
from pathlib import Path

def setup_problem():
    path = Path.cwd()
    name = path.name

    print(f"Problem code: {name}")

    title = input("Title: ") or name
    source = input("Source (default: Unknown): ") or "Unknown"
    diff = input("Difficulty (easy/medium/hard/olympiad, default: medium): ") or "medium"

    r_in = input("Rating (default: 0): ")
    rating = int(r_in) if r_in.isdigit() else 0

    t_in = input("Tags (comma separated, default: unspecified): ")
    tags = [t.strip() for t in t_in.split(",") if t.strip()] or ["unspecified"]

    t_limit = input("Time limit (sec, default: 1.0): ") or "1.0"
    m_limit = input("Memory limit (MB, default: 256): ") or "256"
    is_inter = input("Interactive (y/n, default: n): ").lower() == "y"

    data = {
        "name": name,
        "title": title,
        "source": source,
        "difficulty": diff,
        "rating": rating,
        "tags": tags,
        "limits": {
            "time_limit_sec": float(t_limit),
            "memory_limit_mb": int(m_limit)
        },
        "interactive": is_inter
    }

    with open("problem.json", "w", encoding="utf-8") as f:
        json.dump(data, f, indent=2, ensure_ascii=False)

    old_md = path / "statement" / ".md"
    new_md = path / "statement" / f"{name}.md"

    renamed = False
    if old_md.exists():
        old_md.rename(new_md)
        renamed = True

    print("\nproblem.json created!")
    if renamed:
        print(f"Renamed statement/.md → statement/{name}.md")
    else:
        print("No statement/.md file to rename")
        
    input("Press ENTER to exit...")

if __name__ == "__main__":
    try:
        setup_problem()
    except KeyboardInterrupt:
        print("\nCancelled.")