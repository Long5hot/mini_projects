import pandas as pd
import os
from pydub import AudioSegment
import gtts

def textToSpeechHindi(text, filename):
    mytext = str(text)
    language = 'hi'
    myobj = gtts.gTTS(text = mytext, lang=language, slow=False)
    myobj.save(filename)

def textToSpeechEnglish(text, filename):
    mytext = str(text)
    language = 'en'
    myobj = gtts.gTTS(text = mytext, lang=language, slow=False)
    myobj.save(filename)


# This function returns pydub audio segment
def mergeAudios(audios):
    combined = AudioSegment.empty()
    for audio in audios:
        combined += AudioSegment.from_mp3(audio)

    return combined

def generateSkeleton():
    
    
    
    # 2 -> from city 


    # 3 -> Se chalkar
    start  = 90990  #in milliseconds
    finish = 92206  #
    audioProcessed = audio[start:finish] 
    audioProcessed.export("3_hindi.mp3", format="mp3")

    # 4 is via-city

    # 5 Generating "Ke raste"
    start  = 93840  #in milliseconds
    finish = 94900  #
    audioProcessed = audio[start:finish] 
    audioProcessed.export("5_hindi.mp3", format="mp3")

    # 6 is to->city

    # 7 Generate ko janewali gaadi sankhya

    start  = 96000  #in milliseconds
    finish = 98910  #
    audioProcessed = audio[start:finish] 
    audioProcessed.export("7_hindi.mp3", format="mp3")

    # 8 is train number and name

    # 9 Genrating kuchh hi samay me plateform sankhya
    start  = 105500  #in milliseconds
    finish = 108270  #
    audioProcessed = audio[start:finish] 
    audioProcessed.export("9_hindi.mp3", format="mp3")

    # 10 is platform number

    # 11 -> par aa rahi hee
    start  = 108940  #in milliseconds
    finish = 112250  #
    audioProcessed = audio[start:finish] 
    audioProcessed.export("11_hindi.mp3", format="mp3")



def generateAnnouncement(filename):
    df = pd.read_excel(filename)
    print(df)
    for index, item in df.iterrows():
        # 1 -> Generate "Kripya Dhyan Dijiye"
        textToSpeechEnglish("May i have your attention please! ","1_english.mp3" )

        #2 - Generate train no 
        textToSpeechEnglish(item['train_no'] + " ", '2_english.mp3')

        #3 - Train Name
        textToSpeechEnglish(item['train_name'], '3_english.mp3')

        textToSpeechEnglish("coming from ", "4_english.mp3")

        # 2 _Generate from -city
        textToSpeechHindi(item['from'], '5_english.mp3')

        # 4 Generate Via city
        textToSpeech(item['via'], '4_hindi.mp3')

        #6 - Genrate to -city
        textToSpeech(item['to'], '6_hindi.mp3')
        
        

        #10 - Generate Platform number
        textToSpeech(item['platform'], "10_hindi.mp3")

        audios = [f"{i}_hindi.mp3" for i in range(1,12)]

        announcement = mergeAudios(audios)

        announcement.export(f"announcement_{item['train_no']}_{index+1}.mp3", format="mp3")


if __name__ == "__main__":
    print("Generating Skeleton")
    generateSkeleton()
    print("Now Generating Announcement...")
    generateAnnouncement("announce_hindi.xlsx")