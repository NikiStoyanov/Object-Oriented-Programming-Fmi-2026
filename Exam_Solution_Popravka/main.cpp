
#include <iostream>
#include "Artist.h"
#include <vector>
#include "Playlist.h"
#include "TrackFactory.h"
#include "Reverb.h"
#include "Equalizer.h"
#include "Podcast.h"
#include "MixSession.h"
#include "MusicPlatformException.h"
#include "CommandHistory.h"
#include "AddTrackToPlaylistCommand.h"
#include "AddEffectToChainCommand.h"
#include "Song.h"
using namespace std;

int main()
{
    // Артисти
    Artist artist("Radiohead", Genre::Rock, "");
    cout << artist;

    // Плейлистът се зарежда от конфигурация - типове на траковете;
    // всеки трак се създава чрез фабриката по текстов тип, а данните му
    // (вкл. заглавие) се четат от std::cin
    vector<std::string> config = { "song", "podcast" };

    Playlist listA("Morning Mix"), listB("Workout");
    for (const auto& type : config) {
        auto track = TrackFactory::create(type);
        listA.addTrack(track);
    }
    listA.playAll();

    // Един трак може да е в два плейлиста едновременно
    auto song = listA.findTrack("Creep").value();
    listB.addTrack(song);

    // Сливане на плейлисти - новият плейлист споделя траковете,
    // дубликатите по title се включват само веднъж
    Playlist merged = listA + listB;
    std::cout << merged.size() << "\n";   // 2

    // Нареждане на плейлисти - по обща продължителност, при равенство - по име
    if (listB < listA)
        std::cout << listB.getName() << " е по-кратък\n";

    // Верига от ефекти
    EffectChain chainA, chainB;
    chainA.add(std::make_unique<Reverb>("hall", 0.8f, 1.5f));
    chainA.add(std::make_unique<Equalizer>("eq1", 3, 0, 0));

    chainB = chainA;               // независимо копие
    chainB.add(std::make_unique<Equalizer>("eq2", 1, 1, 1));

    // Конкатенация - combined притежава собствени копия на всички ефекти
    EffectChain combined = chainA + chainB;

    // EffectChain::applyAll - прилага веригата върху един конкретен трак
    auto previewSong = std::make_shared<Song>("No Surprises", 228, 80, "Radiohead", 1997);
    std::cout << previewSong->getVolume() << "\n";   // 80
    chainA.applyAll(*previewSong);
    std::cout << previewSong->getVolume() << "\n";   // volume след всички ефекти от chainA

    // Playlist::applyEffects - прилага подадена верига от ефекти върху всички тракове в плейлиста
    Playlist effectsDemo("Effects Demo");
    auto demoPodcast = std::make_shared<Podcast>("Demo Episode", 600, 50, 1, "Sam");
    effectsDemo.addTrack(demoPodcast);
    effectsDemo.applyEffects(chainB);

    // MixSession::mix - обработва плейлиста с ефектите на сесията и извежда новия volume на всеки трак
    MixSession session("Session A", listA, chainA);
    session.mix();

    // Изключения
    try {
        auto x = TrackFactory::create("bluray");
    }
    catch (const MusicPlatformException& e) {
        std::cout << "Хванато: " << e.what() << "\n";
    }

    // БОНУС: undo
    CommandHistory history;
    history.execute(std::make_unique<AddTrackToPlaylistCommand>(listB, demoPodcast));
    history.execute(std::make_unique<AddEffectToChainCommand>(chainA, std::make_unique<Reverb>("temp", 0.2f, 1.0f)));
    history.undo();   // отменя добавянето на ефекта

    return 0;
}

