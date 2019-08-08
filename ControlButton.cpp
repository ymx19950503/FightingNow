#include "ControlButton.h"
ControlButton::ControlButton():controlBtn(0),isTouch(0)
{
	
}
ControlButton::~ControlButton()
{

}
void ControlButton::CreateButton(const char* name_png,const char* button_title,unsigned int num)
{
	//�õ���ťͼƬ�Ĵ�С 
	CCScale9Sprite* btn = CCScale9Sprite::create(name_png);  
	int  png_height=static_cast<int>(btn->getContentSize().height);
	int  png_width=static_cast<int>( btn->getContentSize().width);
	btn->release();

	//Ҫ��ʾ��ͼƬ��С 
	CCRect rect = CCRectMake(0,0,png_width,png_height);   //ͼƬ�Ĵ�С  
	CCRect rectInsets = CCRectMake(1,1,1,1); //left��right��width��height  
//	CCRect rectInsets = CCRectMake(2,2,png_width-4,png_height-4); //left��right��width��height 

	//��ť����,Marker FeltΪ�������ͣ�png_heightΪ����߶�
	CCLabelTTF *title = CCLabelTTF::create(button_title, "Marker Felt",png_height);  
	title->setOpacity(num);//���ÿɼ���,�����ֿɼ��򲻿ɼ�

	//����״̬�µİ�ťͼƬ 
	CCScale9Sprite *btnNormal = CCScale9Sprite::create(name_png,rect,rectInsets);  
	
	//������ť
	controlBtn = CCControlButton::create(title,btnNormal); 

	//���¼�
	BindButtonEven();
	this->addChild(controlBtn); 

	
}
void ControlButton::BindButtonEven()
{
	if(!controlBtn)
		return;
	controlBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(ControlButton::touchDownAction),CCControlEventTouchDown);  
	controlBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(ControlButton::touchDragEnter),CCControlEventTouchDragEnter);  
	controlBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(ControlButton::touchDragExit),CCControlEventTouchDragExit);  
	controlBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(ControlButton::touchDragInside),CCControlEventTouchDragInside);  	
	controlBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(ControlButton::touchDragOutside),CCControlEventTouchDragOutside);  	
	controlBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(ControlButton::touchUpInside),CCControlEventTouchUpInside);  
	controlBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(ControlButton::touchUpOutside),CCControlEventTouchUpOutside);  
	controlBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(ControlButton::touchCancel),CCControlEventTouchCancel); 
}
/* ����괦�ڰ��²��������а�ťʱ���򴥷�һ�� */  
void ControlButton::touchDownAction(CCObject* pSender, CCControlEvent event)
{
		isTouch=true;

}
/* ����괦�ڰ��²��������а�ť��״̬�£������밴ť��Χ���򴥷�һ�� */  
void ControlButton::touchDragEnter(CCObject* pSender, CCControlEvent event)
{

}
/* ����괦�ڰ��²��������а�ť��״̬�£�����뿪��ť��Χ���򴥷�һ�� */  
void ControlButton::touchDragExit(CCObject* pSender, CCControlEvent event)
{
	
}
/* ����괦�ڰ��²��������а�ť��״̬�£������밴ť��Χ���򴥷���ֻҪ�ﵽ�������Ͳ��ϴ��� */  
void ControlButton::touchDragInside(CCObject* pSender, CCControlEvent event)
{

}
/* ����괦�ڰ��²��������а�ť��״̬�£�����뿪��ť��Χ���򴥷���ֻҪ�ﵽ�������Ͳ��ϴ��� */  
void ControlButton::touchDragOutside(CCObject* pSender, CCControlEvent event)
{
}
/* ����괦�ڰ��²��������а�ť��״̬�£�����ɿ����ڰ�ť��Χ�ڣ��򴥷�һ�� */  
void ControlButton::touchUpInside(CCObject* pSender, CCControlEvent event)
{
		isTouch=false;

}

/* ����괦�ڰ��²��������а�ť��״̬�£�����ɿ����ڰ�ť��Χ�⣬�򴥷�һ�� */  
void ControlButton::touchUpOutside(CCObject* pSender, CCControlEvent event)
{
	
}
/* ��ʱû�з���������괥������¼��Ĳ���������ע�ͣ�Ӧ�����������¼��жϰ�ť�¼��������� */ 
void ControlButton::touchCancel(CCObject* pSender, CCControlEvent event)
{

}