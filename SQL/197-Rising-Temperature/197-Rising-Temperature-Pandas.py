import pandas as pd

def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
    today = weather.copy()
    yesterday = weather.copy()

    today["recordDate"] = pd.to_datetime(today["recordDate"])
    yesterday["recordDate"] = pd.to_datetime(yesterday["recordDate"])

    yesterday["recordDate"] = yesterday["recordDate"] + pd.Timedelta(days=1)

    merged = today.merge(
        yesterday,
        on="recordDate",
        suffixes=("", "_yesterday")
    )

    result = merged[
        merged["temperature"] > merged["temperature_yesterday"]
    ]

    return result[["id"]]
