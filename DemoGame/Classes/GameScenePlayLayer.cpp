#include "System.h"

#include "GameScenePlayLayer.h"

#include "Player.h"

using namespace cocos2d;


void GameScenePlayLayer::TryParticle()
{

	CCParticleSystemQuad *m_emitter = new CCParticleSystemQuad();
	m_emitter->initWithTotalParticles(80);
	m_emitter->autorelease();

	this->addChild(m_emitter, 10);

	CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	CCSpriteFrame *frame = cache->spriteFrameByName("star.png");
	CCTexture2D *texture = frame->getTexture();
	CCRect rect = frame->getRect();

	m_emitter->setEmitterMode(kCCParticleModeGravity);
	m_emitter->setTextureWithRect(texture, rect);

	//m_emitter->setTexture(CCTextureCache::sharedTextureCache()->addImage("fire.png"));
	
	// duration
	m_emitter->setDuration(kParticleDurationInfinity);
	
	// gravity
	m_emitter->setGravity(CCPointZero);
	
	// angle
	m_emitter->setAngle(90);
	m_emitter->setAngleVar(360);
	
	// speed of particles
	m_emitter->setSpeed(160);
	m_emitter->setSpeedVar(20);
	
	// radial
	m_emitter->setRadialAccel(-120);
	m_emitter->setRadialAccelVar(0);
	
	// tagential
	m_emitter->setTangentialAccel(30);
	m_emitter->setTangentialAccelVar(0);
	
	// emitter position
	m_emitter->setPosition( CCPointMake(160,240) );
	m_emitter->setPosVar(CCPointZero);
	
	// life of particles
	m_emitter->setLife(3);
	m_emitter->setLifeVar(1);

	// spin of particles
	m_emitter->setStartSpin(0);
	m_emitter->setStartSpinVar(0);
	m_emitter->setEndSpin(0);
	m_emitter->setEndSpinVar(2000);
	
	// color of particles
	ccColor4F startColor = {0.5f, 0.5f, 0.5f, 1.0f};
	m_emitter->setStartColor(startColor);
	
	ccColor4F startColorVar = {0.5f, 0.5f, 0.5f, 1.0f};
	m_emitter->setStartColorVar(startColorVar);
	
	ccColor4F endColor = {0.1f, 0.1f, 0.1f, 0.0f};
	m_emitter->setEndColor(endColor);
	
	ccColor4F endColorVar = {0.1f, 0.1f, 0.1f, 0.0f};	
	m_emitter->setEndColorVar(endColorVar);

	// size, in pixels
	m_emitter->setStartSize(30.0f);
	m_emitter->setStartSizeVar(00.0f);
	m_emitter->setEndSize(kParticleStartSizeEqualToEndSize);
	
	// emits per second
	m_emitter->setEmissionRate(m_emitter->getTotalParticles()/m_emitter->getLife());

	// additive
	m_emitter->setIsBlendAdditive(true);


}


// on "init" you need to initialize your instance
bool GameScenePlayLayer::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

		CCTexture2D *texture = CCTextureCache::sharedTextureCache()->textureForKey("images.png");
        CCSpriteBatchNode *spriteBatch = CCSpriteBatchNode::batchNodeWithTexture(texture);
        addChild(spriteBatch);

		Player *player = Player::playerWithBatchNode(spriteBatch);
		addChild(player);

		TryParticle();


        bRet = true;

    } while (0);

    return bRet;
}




