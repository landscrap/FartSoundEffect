#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <random>

using namespace geode::prelude;

class $modify(FartMenuLayer, MenuLayer) {

    bool init() {
        if (!MenuLayer::init()) return false;

        auto sprite = CircleButtonSprite::createWithSprite("buttonthing.png"_spr, .9, CircleBaseColor::Green, CircleBaseSize::MediumAlt);

        auto screenSize = CCDirector::sharedDirector()->getWinSize();

        auto button = CCMenuItemSpriteExtra::create(
            sprite,
            this,
            menu_selector(FartMenuLayer::onFart)
        );
        button->setID("fart-button"_spr);

        if (auto menu = this->getChildByID("side-menu")) {
            menu->addChild(button);
            menu->updateLayout();
        }

        return true;
    }

    void onFart(CCObject*) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dist(0.6f, 1.4f);
        FMODAudioEngine::get()->playEffectAdvanced("fart.mp3"_spr, 1, 0, 1, dist(gen), false, false, 0, 0, 0, 0, false, 0, false, false, 0, 0, 0, 0);
    }
};